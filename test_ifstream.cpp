#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char **argv){
    // "~/dataset/MH_01_easy/mav0/imu0/data.csv"
    string path = string(argv[1]);
    cout<< "path: " << path << endl;
    ifstream fImu;
    string a;
    vector<double> vTimeStamps,vAcc,vGyro;
    fImu.open("/home/nx/dataset/MH_01_easy/mav0/imu0/data.csv");
    vTimeStamps.reserve(5000);
    vAcc.reserve(5000);
    vGyro.reserve(5000);
   while(!fImu.eof())
    {
        string s;
        getline(fImu,s,'\n');
        if (s[0] == '#')
            continue;        
        cout << "s: " << s << endl;
        cin >> a;
        if(!s.empty())
        {
            string item;
            size_t pos = 0;
            double data[7];
            int count = 0;
            while ((pos = s.find(',')) != string::npos) {
                item = s.substr(0, pos);
                cout << "item: " << item << endl;
                data[count++] = stod(item);
                s.erase(0, pos + 1);
            }
            item = s.substr(0, pos);
            data[6] = stod(item);

            vTimeStamps.push_back(data[0]/1e9);
        }
        else{
            cout<< "s is empty!\n";
        }
    }
    return 0;
}