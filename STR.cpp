#include <iostream>
#define MAX 10

using namespace std;

struct Task{
    int j,c,p,d;

    Task(int jj = 0, int cc = 0, int pp = 0, int dd = 0){
        j = jj;
        c = cc;
        p = pp;
        d = dd;}

    friend ostream &operator<<(ostream &out, Task t){
        out << t.j << " " << t.c << " " << t.p << " " << t.d;
        return out;}

};

void print(Task *tasks, int numTasks){
    for(int i = 0; i < numTasks; i++)
        cout << tasks[i] << endl;}

int main(){
    Task tasks[MAX];
    int numTasks;

    while(1){
        //Input//
        cin >> numTasks;
        if(!numTasks) break;

        for(int i = 0; i < numTasks; i++)
            cin >> tasks[i].j >> tasks[i].c >> tasks[i].p >> tasks[i].d;

        //Processamento//
        int w[2] = {tasks[numTasks-1].c};
        int r = 0;
        int i = 0;

        do{
            w[1] = (i+1)*tasks[numTasks-1].c;
            for(int j = 0; j < numTasks-1; j++)
                w[1] += ((w[0]+tasks[j].j)/tasks[j].p + ((w[0]+tasks[j].j) % tasks[j].p) ? 1 : 0)*tasks[j].c;
            
            w[0] = w[1];

            if(r < tasks[numTasks-1].j + w[0] - i*tasks[numTasks-1].p) 
                r = tasks[numTasks-1].j + w[0] - i*tasks[numTasks-1].p;
        }while(w[0] > ++i*tasks[numTasks-1].p);
    
        //Output//
        cout << numTasks << " " << r << " " << ((r <= tasks[numTasks-1].d) ? "YES":"NO") << endl;}
}