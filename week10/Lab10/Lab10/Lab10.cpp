#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <string>
#include <functional>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;
// the CommandManager class should implement a mini terminal that receive commands and dispatches them.
// example: copy a.jpg b.jpg
// this will search the map for a "copy" command, and if it finds it, it will invoke its callback with a vector made of
// {"a.jpg", "b.jpg"} no global variables allowed

class CommandManager
{
  private:
    map<string, function<void(vector<string>)>> commands;
  public:
    void add(string name, function<void(vector<string>)> fn);
    // run shall read a line from stdin in a loop, split it by whitespaces.
    // the first word will be the command name. if no word has been found, it will do nothing
    // then it will search the map for the name, and it will invoke the callback if it founds it
    // or it will show a message if it can't find it
    // the args for the callback will not contain the command name
    // if the `stop` command is found, the function will return
    // try doing this yourself; if you spent too much time on this, look at
    // https://gist.github.com/rzaharia/0e155df56a3a81d5383f00d838c97a99
    void run();
};

void CommandManager::add(string name, function<void(vector<string>)> fn)
{
    commands[name] = fn;
}
void CommandManager::run()
{
    string tmp;
    vector<string> v;

    while (true)
    {
        getline(cin, tmp);
        if (tmp == "stop")
            return ;
        v.clear();
        auto ptr = strtok(&tmp[0], " ");
        while (ptr)
        {
            v.push_back(ptr);
            ptr = strtok(nullptr, " ");
        }

        if (v.empty())
        {
            continue;
        }

        auto it = commands.find(v[0]);
        if (it==commands.end())
        {
            printf("no command with that name!\n");
            continue;
        }
        v.erase(v.begin());
        it->second(v);
    }
}

int main()
{
    CommandManager manager;
    // number_of_errors represents the number of IO errors (eg. file errors) that happened in the commands
    // this is only relevant for the append and copy commands
    unsigned number_of_errors = 0;
    unsigned number_of_calls  = 0;

    // prints pong!
    auto ping = [](vector<string> args) { printf("pong!\n"); };
    manager.add("ping", ping);

    // prints the number of arguments it received
    // `count a b c` -> will print `counted 3 args`
    auto count = [](vector<string> args) { printf("%d", args.size()); };
    manager.add("count", count);

    // the first argument will be treated as a file name
    // the rest of the arguments will be appended to that file with a space as delimiter
    // remember to count the errors, if any
    auto append = [&number_of_errors](vector<string> args)
    {
        if (args.size()==0)
        {
            number_of_errors += 1;
            return;
        }
        fstream fp;
        fp.open(args[0], fstream::app);
        if (!fp)
        {
            number_of_errors+=1;
            return;
        }
        for (int i=1;i<args.size();i++)
        {
            fp << " " << args[i];
        }
        fp.close();
    };
     manager.add("append", append);

    // will print the number of times the command was called
    // do not capture any reference for this lambda
     auto times = [count = number_of_calls](vector<string> args)mutable
     {
         count++;
         printf("%d times\n", count);
     };
     manager.add("times", times);

    // copy a file; args[0] will provide the source, and args[1] the destination
    // make sure it works with binary files (test it with an image)
    // remember to count the errors, if any
     auto copy = [&number_of_errors](vector<string> args)
     {
         if (args.size() != 2)
         {
             number_of_errors++;
             return;
         }
         fstream in(args[0], ios::binary | ios::in);
         fstream out(args[1], ios::binary | ios::out);
         char c;
         while (true)
         {
             c = in.get();
             if (in.eof())
                 break;
             out.put(c);
         }
         in.close();
         out.close();
     };
    manager.add("copy", copy);

    // will sort the arguments by size
    // `sort_size abc a 1234` -> will print `a abc 1234`
    // use std::sort with a lambda comparator to sort
    // and std::for_each with a lambda to print afterwards
    auto sort_size = [](vector<string> args) {
        sort(args.begin(), args.end(), [](const string a,const string b) -> bool { return a.size() < b.size(); });
        for_each(args.begin(), args.end(), [](const string& str) -> void { std::cout << str << " "; });
        printf("\n");
    };
     manager.add("sort_size", sort_size);

    // add one more command of anything you'd like
     auto rot13 = [](vector<string> args)
     {
         for (auto val : args)
         {
             for (int i = 0; i < val.size(); i++)
                 if ((val[i] >= 'A' && val[i] <= 'Z') || (val[i] >= 'a' && val[i] <= 'z'))
                 {
                     if (val[i] >= 'N' && val[i] <= 'Z')
                         val[i] = 'A' + (val[i] + 13 - 'Z' - 1);
                     else if (val[i] >= 'n' && val[i] <= 'z')
                         val[i] = 'a' + (val[i] + 13 - 'z' - 1);
                     else
                         val[i] = val[i] + 13;
                 }
             cout << val << " ";
         }
     };
     manager.add("rot13", rot13);
    manager.run();

    printf("number of errors: %u\ndone!\n", number_of_errors);
}