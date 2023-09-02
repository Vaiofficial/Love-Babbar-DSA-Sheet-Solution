for(int row=0;row<n;row++)
    {
        for(int star=0;star<row;star++)
        {
            cout<<" ";
        }
        for(int star=0;star<n-row;star++)
        {
            cout<<"* ";
        }
        cout<<endl;

    }