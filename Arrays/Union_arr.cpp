#include<iostream>
#include<vector>
using namespace std;

vector<int> a{1,2,3,4,5,9};
vector<int> b{1,2,3};
vector<int> ans;

void Union()
{
    for (int i = 0; i < a.size(); i++)
    {
        ans.push_back(a[i]);
    }


    for (int i = 0; i < b.size(); i++)
    {
        bool found = false;
        for (int j = 0; j < a.size(); j++)
        {
            if (b[i] == a[j])
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            ans.push_back(b[i]);
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout<<endl;
}


void Intersection()
{
    vector<int> ans;
    for (int i = 0; i < a.size(); i++)
    {
        int ele = a[i];
       
        for (int j = 0; j < b.size(); j++)
        {
            if (ele == b[j])
            {
                ans.push_back(ele);
            }
        }
        
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    Union();
    Intersection();
    return 0;
}
