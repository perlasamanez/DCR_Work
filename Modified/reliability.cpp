// Modify as you please. Let me know if it makes no sense at all. 

#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

// Formula
float R(float p, int e, int d, vector< vector<int> > S) 
{
    int i;
    float Sum = 0.0;    
     
    for (i = 0; i <= e; i++)
    {       
       Sum += S[d][i]*pow(p,i)*pow((1.0 - p), (e-i)); 
    }

    return Sum;
}

// To compare between normal reliability and swing surgery, looking for d0
void d_comparison(int n, int e, vector< vector<int> > S_1, vector< vector<int> > S_2)
{
    int p_counter, d, d0_counter, d0[1001];
    float p;
    // Diameter constraint is to be used as at the most the number of (vertices(n) - 1). Thus, d = n - 1. 
    float R1[1001][n-1];
    float R2[1001][n-1];

    ofstream filed0_;
    //ofstream file_ds_only;
    //ofstream file_all;
    
    filed0_.open("Filed0.txt");
    //file_ds_only.open("File_for_ds.txt");
    //file_all.open("File_all.txt");
    

    for (p_counter = 0; p_counter <= 1000; p_counter++)
    {
        for (d = 0; d <= n-1; d++)
        {
            // Getting the p value from 0 to 1. Increasing by 0.001
            p = p_counter/1000.0;
            
            // Fixed p for this for loop, d keeps growing from 0 to 9
            R1[p_counter][d] = R(p, e, d, S_1);

            R2[p_counter][d] = R(p, e, d, S_2); 
        
            //if (file_all.is_open())
                //file_all << "For probability: " << p << " this is its d value: " << d << ". With 1st Re: " << R1[p_counter][d] << " and 2nd Re: " << R2[p_counter][d] << "\n";

            
            if (R2[p_counter][d] >= R1[p_counter][d])
            { 
                //if (file_ds_only.is_open())
                    //file_ds_only << "For probability: " << p << " for these d value " << d << " R2 is greater than R1." << "\n";
 
                //Ignoring p = 0 and p = 1
                if (p < 1.0 && p >= 0.001)
                {
                    d0[p_counter] = d;
                        
                    if (d0[p_counter] > 3)
                    {
                       if (filed0_.is_open())
                       {
                            filed0_ << "For p = " << p << ", d0 = " << d0[p_counter] << "\n";
                            break;
                       }
                    }
                }         
            } 
         }
    }

     d0_counter = std::count(d0, d0+1001, 6);

    
     if (d0_counter >= 900)
        cout << "d0 for the graph (for most probabilities) with: " << n << " vertices and " << e << " edges is: " << d0[1] << endl; 

    filed0_.close();
    //file_ds_only.close();
    //file_all.close();
}
