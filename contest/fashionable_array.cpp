#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>


#define ll long long

using namespace std;



// pair<int, int> getMax(vector<int> & arr, int size){
//     int maxVal = -1;
//     int maxIndex = 0;
//     for (size_t i =0 ; i <size ; i++){
//         if (arr[i] > maxVal ){
//             maxVal = arr[i];
//             maxIndex = i;
//         }
//     }

//     return {maxVal, maxIndex};
// }


// pair<int, int> getMin(vector<int> & arr, int size){
//     int minVal = 1 << 26;
//     int minIndex = 0;
//     for (size_t i =0 ; i <size ; i++){
//         if (arr[i] < minVal ){
//             minVal = arr[i];
//             minIndex = i;
//         }
//     }

//     return {minVal, minIndex};
// }

int main(){

    // odd + odd = even
    // even + even = odd
    // odd + even or vice versa is odd

    int tests {};
    cin >> tests;

    for (size_t i =0; i < tests; i++){

        vector<int> arr {};

        int size {};
        cin >> size;

        int temp {size};
        while (temp!=0){
            int tempNum{};
            cin >> tempNum;
            arr.push_back(tempNum);
            temp--;
        }


        stable_sort(arr.begin(), arr.end()); // n log n

        if (arr[0]+arr[size-1] % 2 ==0){
            cout << 0 <<endl;
        }else{
            // either one of them is odd or even
            // three loops
            int operations {1<<25};
            int cOne {0};
            int CTwo{size -1};
            int sum {arr[cOne] +arr[CTwo]};
            while (sum % 2 !=0 && cOne<size && CTwo>0){
                if (arr[cOne] % 2 ==0 && arr[CTwo] %2 !=0){
                    if (arr[cOne+1] %2 !=0){
                        cOne++;
                        if (operations == 1<<25){
                            operations =1;
                        }else{
                            operations++;
                        }
                        
                    }else{
                      if (arr[CTwo-1] % 2 ==0){
                        CTwo--;
                        if (operations == 1<<25){
                            operations =1;
                        }else{
                            operations++;
                        }
                      }  
                      else{
                        if (operations == 1<<25){
                            operations =2;
                        }else{
                            operations+=2;
                        }
                        CTwo--;
                        cOne++;
                      }
                    }
                } else if (arr[cOne] % 2 !=0 && arr[CTwo] %2 ==0) {
                    if (arr[cOne+1] %2 ==0){
                        cOne++;
                        if (operations == 1<<25){
                            operations =1;
                        }else{
                            operations++;
                        }
                    }else{
                      if (arr[CTwo-1] % 2 !=0){
                        CTwo--;
                        if (operations == 1<<25){
                            operations =1;
                        }else{
                            operations++;
                        }
                      }  
                      else{
                        if (operations == 1<<25){
                            operations =2;
                        }else{
                            operations+=2;
                        }
                        CTwo--;
                        cOne++;
                      }
                    }
                }
                sum = arr[cOne]+arr[CTwo];
            }

            int operation_2 {1};
            for (size_t i = 0; i < size-1; i++)
            {
                if ((arr[i]+arr[size-1]) %2 == 0){
                    operation_2= i+1;
                    break;
                }
            }

            int operation_1 {1};
            for (size_t i = size-1; i >0; i++)
            {
                if ((arr[i]+arr[0]) %2 == 0){
                    operation_1= size-i;
                    break;
                }
            }
            cout << min(operation_1, min(operation_2, operations)) << endl;

        }

        // auto [maxVal, maxIndex] = getMax(arr, size);
        // auto [minVal, minIndex] = getMin(arr, size);

        // while ((maxVal+minVal) % 2 != 0){
        //     // edge case is alternating values


        //     //


        //     auto [maxVal, maxIndex] = getMax(arr, size);
        //     auto [minVal, minIndex] = getMin(arr, size);
        // }


        

    }




    
}
