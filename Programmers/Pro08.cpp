#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(const pair<string, int>& a, const pair<string, int>& b) {
    if(a.first == b.first) {
        return a.second < b.second;
    } else {
        return a.first < b.first;
    }
}

int solution(vector<string> lines) {
    int answer = 0;
    int size = lines.size();
    vector<pair<string, int>> convLogs;
    int hour, min, second, milliSecond, responseSecond, responseMilliSecond;
    int startHour, startMin, startSecond;
    string startTime, endTime;
    
    for(int i = 0; i < size; i++) {
        hour = stoi(lines[i].substr(11, 2));
        min = stoi(lines[i].substr(14, 2));
        second = stoi(lines[i].substr(17, 2) + lines[i].substr(20, 3));
        
        if(int(lines[i].rfind('.')) == 25) { 
            responseMilliSecond = stof(lines[i].substr(25)) * 1000;
            if(responseMilliSecond < 10) {
                responseSecond = stoi("0" + lines[i].substr(24, 1) + "00" + to_string(responseMilliSecond));
            } else if(responseMilliSecond < 100) {
                responseSecond = stoi("0" + lines[i].substr(24, 1) + "0" + to_string(responseMilliSecond));
            } else {
                responseSecond = stoi("0" + lines[i].substr(24, 1) + to_string(responseMilliSecond));
            }
            
        } else {
            responseSecond = stoi("0" + lines[i].substr(24, 1) + "000");
        }
        
        //conv
        startSecond = second - responseSecond + 1;
        startMin = min;
        startHour = hour;
        
        //cout << startSecond << endl;
        
        if(startSecond < 0) {
            startSecond += 60000;
            startMin -= 1;
        }
        //cout << startSecond << endl;
        
        if(startMin < 0) {
            startMin += 60;
            startHour -= 1;
        }
        
        //endTime
        endTime = "";
        
        if(hour < 10) {
            endTime += "0" + to_string(hour);
        } else {
            endTime += to_string(hour);
        }
        
        if(min < 10) {
            endTime += "0" + to_string(min);
        } else {
            endTime += to_string(min);
        }
        
        if(second < 10) {
            endTime += "0000" + to_string(second);
        } else if(second < 100) {
            endTime += "000" + to_string(second);
        } else if(second < 1000) {
            endTime += "00" + to_string(second);
        } else if(second < 10000) {
            endTime += "0" + to_string(second);
        } else {
            endTime += to_string(second);
        }
        
        //startTime
        if(startHour < 0) {
            startTime = "000000000";
        } else {
            startTime = "";
            
            if(startHour < 10) {
                startTime += "0" + to_string(startHour);
            } else {
                startTime += to_string(startHour);
            }

            if(startMin < 10) {
                startTime += "0" + to_string(startMin);
            } else {
                startTime += to_string(startMin);
            }

            if(startSecond < 10) {
                startTime += "0000" + to_string(startSecond);
            } else if(startSecond < 100) {
                startTime += "000" + to_string(startSecond);
            } else if(startSecond < 1000) {
                startTime += "00" + to_string(startSecond);
            } else if(startSecond < 10000) {
                startTime += "0" + to_string(startSecond);
            } else {
                startTime += to_string(startSecond);
            }
        }
        
        convLogs.push_back({startTime, 0});
        convLogs.push_back({endTime, 1});
    }
    
    //C++ 소팅 
    sort(convLogs.begin(), convLogs.end(), compare);
    
    int vec_size = convLogs.size();
    int temp = 0, check_temp = 0;
    int vec_temp = 0;
    
    for(int i = 0; i < vec_size; i++) {
        if(convLogs[i].second == 0) {
            temp += 1;
            if(answer < temp) answer = temp;
        } else {
            check_temp = temp;
            for(int j = i+1; j < vec_size; j++) {
                if((stoi(convLogs[j].first) - stoi(convLogs[i].first)) < 1000) {
                    if(convLogs[j].second == 0) {
                        check_temp += 1;
                        if(answer < check_temp) answer = check_temp;
                    }
                } else {
                    break;
                }
            }
            temp -= 1;
        }
    }
    
    return answer;
}
