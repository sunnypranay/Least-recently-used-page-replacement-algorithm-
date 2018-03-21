#include<iostream>
using namespace std;
class page_table
{
public:
    int no_of_pages,no_of_frames,page_fault=0,position=0,index=0,index1=0,count1=1;
    int frequency_array[100];
    int pages[100];
    int frames[100];
    page_table(int a,int b)
    {
        no_of_pages=a;
        no_of_frames=b;
        page_fault=no_of_frames;

        for(int i=0;i<no_of_frames;i++)
        {
            frames[i]=-1;
            frequency_array[i]=0;
        }
    }
    void get_pages()
    {
        cout<<"Enter the pages one after the another\n";
        for(int i=0;i<no_of_pages;i++)
        {
            cin>>pages[i];
        }
    }
    void intial_step()
    {
        for(int i=0;i<no_of_frames;i++)
        {
            frames[i]=pages[i];
            for(int j=0;j<=i;j++)
            {
                frequency_array[j]+=1;
            }
            print();
        }
    }
    bool check(int i1)
    {
        for(int i=0;i<no_of_frames;i++)
        {
            if(frames[i]==pages[i1])
            {

                index1=i;
                return true;
            }
        }
        return false;
    }
    void dead(int i1)
    {

        frequency_array[i1]=0;


    }
    int greatest()
    {
        int max1=frequency_array[0];
        for(int i=0;i<no_of_frames;i++)
        {
            if(max1<=frequency_array[i])
            {
                max1=frequency_array[i];
                index=i;
            }
        }

        return index;
    }
    void print()
    {
        cout<<"frames is\n";
        for(int i=0;i<no_of_frames;i++)
        {
            cout<<frames[i]<<"  ||  ";
        }
        cout<<"\n\n";
    }
    int lru()
    {
        for(int i=no_of_frames;i<no_of_pages;i++)
        {


            if(check(i)==true)
            {


                dead(index1);

                       for(int j=0;j<no_of_frames;j++)
            {
                if(index1==j)
                {
                    continue;
                }
                frequency_array[j]+=1;
            }
            print();
                continue;

            }
            else{
                position=greatest();


                frames[position]=pages[i];
                dead(position);
                 for(int j=0;j<no_of_frames;j++)
            {
                if(position==j)
                {
                    continue;
                }
                frequency_array[j]+=1;
            }
            page_fault++;



            }
            print();
        }

        return page_fault;
    }


};
int main()
{
    int a,b,c;
    cout<<"Enter the number of pages:\n";
    cin>>a;
    cout<<"Enter the number of frames:\n";
    cin>>b;
    page_table p(a,b);
    p.get_pages();
    p.intial_step();
    cout<<"page fault is "<<p.lru();

}
