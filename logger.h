namespace Logger
{
    using namespace std;
    class Logger
    {
    private:
        vector<string> logs;
        static Logger *instance;
        Logger(){}
    public:

        static Logger *getInstance()
        {
            if(!instance)
            {
                instance=new Logger;
            }
            return instance;
        }

        void updateLogs(string log)
        {
            logs.push_back(log);
        }

        void viewLogs()
        {
            cout<<"\n==========Logs=========="<<endl;
            int i=1;
            for(string log : logs)
            {
                cout<<i++<<":"<<log<<endl;
            }

        }
    };
}
