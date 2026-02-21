#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n=4;
    int item_w[]= {2,1,5,3};
    int  item_val[] ={140,200,150,240};
    float val_per_weight[4];
    int capacity =5;
    int weight =0;
    float profit=0;
    vector<pair < float, pair< int, int > > >itemTab;


    for(int i=0; i<n; i++)
    {
        val_per_weight[i]= item_val[i]/item_w[i];
        cout<<val_per_weight[i]<< "\t\t";
        itemTab.push_back(make_pair(val_per_weight[i], make_pair(item_val[i], item_w[i])));

    }//for
cout<<endl;
cout<<endl;
        cout<< "v/w\tBenefit\t      weight"<<endl;
        for (int i=0; i<n; i++)
        {
            cout<<itemTab[i].first<< "\t "
            <<itemTab[i].second.first<< " \t\t"
            <<itemTab[i].second.second<< endl;
        }

        sort (itemTab.begin(), itemTab.end(), greater<>());
        cout<< "\n\nv/w\tBenefit\       weight"<<endl;
        for (int i=0; i<n; i++)
        {
            cout<<itemTab[i].first<< "\t "
            <<itemTab[i].second.first<< "\t\t"
            <<itemTab[i].second.second<< endl;
        }

        for (int i=0; i<n; i++)
        {
            int wi= itemTab[i].second.second;
            int pi= itemTab [i].second.first;
            if(weight+wi<= capacity)
            {
                weight= weight+ wi;
                profit= profit+pi;
            }//if
            else
            {
                int rem= capacity- weight;
                weight= weight+rem;
                profit= profit+(float)rem*itemTab[i].first;
                break;
            }//
        }
        cout<< "\nMax profit: "<< profit;

    /* ----------  NEW: show chosen items (indices)  ---------- */
    cout << "\n\nSelected item indices: ";
    int w = 0;
    for (int i = 0; i < n && w < capacity; ++i)
    {
        int wi = itemTab[i].second.second;
        int pi = itemTab[i].second.first;
        if (w + wi <= capacity)
        {
            w += wi;
            cout << (itemTab[i].second.first == item_val[0] && wi == item_w[0] ? 0 :
                     itemTab[i].second.first == item_val[1] && wi == item_w[1] ? 1 :
                     itemTab[i].second.first == item_val[2] && wi == item_w[2] ? 2 : 3) << " ";
        }
        else
        {
            cout << (itemTab[i].second.first == item_val[0] && wi == item_w[0] ? 0 :
                     itemTab[i].second.first == item_val[1] && wi == item_w[1] ? 1 :
                     itemTab[i].second.first == item_val[2] && wi == item_w[2] ? 2 : 3) << "(part) ";
            w = capacity;
        }
    }
    /* ----------  END NEW BLOCK  ---------- */

    return 0;
};
