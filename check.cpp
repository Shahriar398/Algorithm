#include<iostream>
#include<conio.h>
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
    vector<pair < float, int > >itemIndex; // To track original item numbers

    for(int i=0; i<n; i++)
    {
        val_per_weight[i]= item_val[i]/item_w[i];
        cout<<val_per_weight[i]<< "\t\t";
        itemTab.push_back(make_pair(val_per_weight[i], make_pair(item_val[i], item_w[i])));
        itemIndex.push_back(make_pair(val_per_weight[i], i+1)); // Store original item number
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
        sort (itemIndex.begin(), itemIndex.end(), greater<>());
        cout<< "\n\nv/w\tBenefit\       weight"<<endl;

        for (int i=0; i<n; i++)
        {
            cout<<itemTab[i].first<< "\t "
            <<itemTab[i].second.first<< "\t\t"
            <<itemTab[i].second.second<< endl;
        }

        cout<<"\nItems selected: ";

        for (int i=0; i<n; i++)
        {
            int wi= itemTab[i].second.second;
            int pi= itemTab [i].second.first;
            int itemNum = itemIndex[i].second;

            if(weight+wi<= capacity)
            {
                weight= weight+ wi;
                profit= profit+pi;
                cout<<itemNum<<" ";
            }//if
            else
            {
                int rem= capacity- weight;
                if(rem > 0)
                {
                    weight= weight+rem;
                    profit= profit+(float)rem*itemTab[i].first;
                    cout<<itemNum<<" ";
                    cout<<endl;
                }
                break;
            }//
        }
        cout<< "\nMax profit: "<< profit;
    getch();
};
