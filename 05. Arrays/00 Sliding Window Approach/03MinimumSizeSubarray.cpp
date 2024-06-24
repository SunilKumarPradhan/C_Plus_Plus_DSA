#include <bits/stdc++.h>
using namespace std;

int MinSub(int arr[], int n, int target){
    int l = 0;
    int r = 0;
    int minLen = INT_MAX;
    int sum = 0;

    while (r < n) {
        sum += arr[r];

        while (sum >= target) {
            minLen = min(minLen, r - l + 1);
            sum -= arr[l];  // thoda focus karna hoga but ye easy hai.
            l++;
        }
        r++;
    }

    return (minLen == INT_MAX) ? 0 : minLen;
}

int main() {
    int target=7;
    int arr[]={2,3,1,2,4,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"The Length of the Minimum Subarray : "<<MinSub(arr,n,target)<<endl;
    return 0;
}



/*
यह कोड स्लाइडिंग विंडो तकनीक का उपयोग करके एक ऐसे सबसे छोटे सबअरे की लंबाई को ढूंढने के लिए है, जिसका योग सीमा (target) से अधिक या बराबर हो। यहां समझाया गया है:

फ़ंक्शन की शुरुआत:

MinSub फ़ंक्शन arr, n, और target के साथ काम करता है। arr एक एरे है जिसमें हमें सबसे छोटे सबअरे की लंबाई ढूंढनी है, n एरे के आकार को दर्शाता है और target एक निर्दिष्ट सीमा है जिससे बड़े या बराबर योग को ढूंढना है।
चर्चा का आगमन:

l, r, minLen, और sum की शुरुआत इंटीजी मैक्सिमम (INT_MAX) के साथ की जाती है। l और r स्लाइडिंग विंडो के बायें और दायें सीमा को दर्शाते हैं, minLen निकलने वाले सबअरे की सबसे कम लंबाई रखता है, और sum मौजूदा स्लाइडिंग विंडो की योग को दर्शाता है।
वाइल लूप:

r < n तक जब तक की स्थिति बनी रहे, sum में arr[r] अंदर दर्ज किया जाता है।
आंतरिक वाइल लूप:

sum >= target तक जब तक की स्थिति बनी रहे, minLen और r - l + 1 के मध्य सबसे कम लंबाई को चुना जाता है और sum से arr[l++] घटाया जाता है।
राइट इंडेक्स बढ़ाना:

r बढ़ाया जाता है, ताकि अगली स्थिति के लिए स्लाइडिंग विंडो को बढ़ाया जा सके।
नतीजा:

minLen == INT_MAX हो, तो 0 वापस आता है, अन्यथा minLen की मान वापस आती है।
इस तरह, यह कोड एक अच्छे तरीके से स्लाइडिंग विंडो का उपयोग करके योग सीमा से अधिक या बराबर के सबसे छोटे सबअरे की लंबाई को निकालता है।*/
