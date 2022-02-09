#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#define music 0
#define img   1
#define mov   2
#define other 3




int main()
{
    int total_size[4]{0,0,0,0};//[0]music [1]img [2]mov [3]other
    int NumOfTestCases{0};
    cin>>NumOfTestCases;
    int *NumOfLines{new int[NumOfTestCases]};
    
    for(int i=0;i<NumOfTestCases;i++)
    {
        cin>>NumOfLines[i];
        //cout<<NumOfLines[i];
    }
    for(int i=0;i<NumOfTestCases;i++)
    {
        string *str{new string[NumOfLines[i]]};
        for(int j=0;j<NumOfLines[i];j++)
        {
/*
2 3 2
dragons.song .mp3 11b
theGreatGig.flac 1000b
file.txt 5b
out.exe 100b
inception.mkv 10000b
*/
            getline(cin >> ws, str[j]);
            stringstream s(str[j]);
            string ext,str_size;
            while(getline(s,ext,'.'));
            //cout<<"1-ext= "<<ext<<endl;
            s.str("");
            s.clear();
            s<<ext;
            //cout<<"s<<ext "<<s.str()<<endl;
            getline(s,ext,' ');
            //cout<<"2-ext= "<<ext<<endl;
            getline(s,str_size,'b');
            //cout<<"size= "<<str_size<<endl;
            int int_size;
            stringstream ss(str_size);
            //s<<;
            ss>>int_size;
            //cout<<"str_size= "<<str_size<<" int_size = "<<int_size<<endl;
            if(ext== "mp3"||ext=="aac"||ext== "flac")
            {
                //cout<<"-------------flac+"<<endl;
                total_size[music]+=int_size;
            }
            else if(ext== "jpg"||ext== "bmp"||ext== "gif")
            {
                total_size[img]+=int_size;
            }
            else if(ext== "mp4"||ext== "avi"||ext== "mkv")
            {
                total_size[mov]+=int_size;
            }
            else
            {
                total_size[other]+=int_size;
            }
        }
        cout<<"music "<<total_size[music]<<"b images "<<total_size[img]<<"b movies "<<total_size[mov]<<"b other "<<total_size[other]<<"b"<<endl;
        for(int k=0;k<4;k++)
        {
            total_size[k]=0;
        }
    }
    return 0;
}

