#include <iostream>
using namespace std;
int main(){
    int arr[10]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int num;
    cout<<"Enter a number to search for: ";
    cin>>num;
    bool found = false;
    for(int i = 0; i < 10; ++i){
        if(arr[i] ==num){
            cout<<"Number "<<num<<"found at index " <<i<<endl;
            found = true;
            break;
        }
    }
    if(!found){
        cout<< "Number not found in the array" <<endl;
    }
    return 0;
}
