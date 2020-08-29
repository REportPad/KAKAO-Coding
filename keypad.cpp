#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int N = numbers.size();
    int lx = 3, ly = 0;
    int rx = 3, ry = 2;
    
    for(int i=0; i < N; ++i){
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){//c2
            answer += 'L';
            lx = numbers[i]/3;
            ly = 0;
        }
        else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){//c3
            answer += 'R';
            rx = numbers[i]/4;
            ry = 2;
        }
        else{//2,5,8,0 c3
            if(numbers[i] == 0) numbers[i] = 11;
            int dist[2] = {0,};
            int dx = numbers[i]/3;
            dist[0] = abs(lx - dx) + abs(ly -1);
            dist[1] = abs(rx - dx) + abs(ry -1);
            
            if(dist[0] < dist[1]){
                answer += 'L';
                ly = 1;
                lx = dx;
            }
            else if(dist[0] > dist[1]){
                answer += 'R';
                ry = 1;
                rx = dx;
            }
            else{//dr == dl
                if(hand == "right"){
                    answer += 'R';
                    ry = 1;
                    rx = dx;
                }
                else{
                    answer += 'L';
                    ly = 1;
                    lx = dx;
                }
            }
        }
    }
    
    return answer;
}
