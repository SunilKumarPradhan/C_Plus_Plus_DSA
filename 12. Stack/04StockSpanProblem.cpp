//Stock Span Problem ko solve karne ke liye aapko ye check karna hai ki har ek din ke liye 
//pichle consecutive kitne dino tak ke stock prices current din ke stock price se kam ya barabar hain. 
//Aapko ye span values find karni hain.

//Har din ke liye aapko pichle dino ke prices check karne hain jo current din ke price se kam ya barabar hain.





// int findSpan(int arr[] ,int n){
//     stack<int> st;

// }


#include <bits/stdc++.h>
using namespace std;

// void findSpan(int arr[] , int n){
//     for(int i =0;i<n;i++){
//         int span=1;
//         for(int j=i-1;  j>=0 && arr[j]<arr[i]  ;j--){
//             span++;
//         }
//         cout<<span<<" ";
//     }
// }
#include <bits/stdc++.h>
using namespace std;

void findSpan(int arr[] , int n){
    stack<int> st;
    st.push(arr[0]);

    for(int i =0; i<n;i++){
        while(st.empty()==false && arr[st.top()] <= arr[i]){ //while(st.empty() == false && arr[st.top()] <= arr[i]): जब तक स्टैक खाली नहीं है और स्टैक का टॉप एलिमेंट arr[i] से छोटा या बराबर है, स्टैक से टॉप एलिमेंट को हटाते रहना।
            st.pop();
        }
         int span=st.empty() ? i+1 : i - st.top();
        cout<<span<<" ";
        st.push(i);
    }
}

int main() {
    int arr[]={18,12,13,14,11,16};
    int n=sizeof(arr)/sizeof(arr[0]);
    findSpan(arr, n);
    return 0;
}

// span = left side mein jitne chote hain + 1
/*Inner Loop:

for (int j = i - 1; j >= 0 && arr[j] <= arr[i]; j--):
Ye loop current din se pichle din tak jata hai.
Jab tak arr[j] current din ke price se kam ya barabar hai, tab tak loop chalta rahega aur span ko increment karta rahega.*/


/*
जब स्टैक खाली है (st.empty() == true):

इसका मतलब है कि arr[i] के लेफ्ट में कोई भी ऐसा एलिमेंट नहीं है जो arr[i] से बड़ा या बराबर हो।
इसलिए स्पैन होगा i + 1।
उदाहरण के लिए, अगर i = 2, तो span = 2 + 1 = 3।
*/

/*


*/