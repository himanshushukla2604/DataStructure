#include<iostream>
#include <vector>
using namespace std;
void bubbleSort(vector<int>&arr){
    int isSorted = 0;
    for(int i = 0 ; i < arr.size(); i++){
        isSorted = 1;
        for(int j = 1 ; j < arr.size() - i; j++){
            if(arr[j-1] > arr[j]){
                int temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
                isSorted = 0;
            };

        }
        if(isSorted == 1){
            return;
        }
    }
}
int main(){
    vector<int> arr;
    int numOfElement, num;
    cout<<"Enter the number of elements.";
    cin>> numOfElement;
    for(int i = 0 ; i< numOfElement; i++){
        cin>>num;
        arr.push_back(num);
    }
    bubbleSort(arr);
    for(int i = 0; i< arr.size();i++){
        cout<<arr[i]<< " ";
    }
}