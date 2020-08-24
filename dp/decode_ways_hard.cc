class Solution {
public:
    int numDecodings(string s) {
        int size = s.size();
        long dp[size];
        if(s[size-1]=='0')
        {
            dp[size-1]=0;
        }
        else if(s[size - 1] == '*')
        {
            dp[size - 1] = 9;
        } else {
            dp[size - 1] = 1;
        }
        for(int i=s.size()-2; i>=0; i--)
        {
            if(s[i]=='0')
            {
                dp[i]=0;
            }
            else if( s[i] == '*') {
                dp[i] = dp[i + 1] + 8;
                if( i == size -2) {
                    if (s[i + 1] <= '6' && s[i + 1] >= '0') {
                        dp[i] += 2;
                    } else if(s[i + 1] >= '7' and s[i + 1] <= '9') {
                        dp[i] += 1;
                    } else {
                        dp[i] += 15;
                    }

                } else {
                    if (s[i + 1] <= '6' && s[i + 1] >= '0') {
                        dp[i] += 1  + dp[i + 2];
                    } else if(s[i + 1] >= '7' and s[i + 1] <= '9') {
                        dp[i] += dp[i + 2];
                    } else {
                        dp[i] += dp[i + 2] + 14;
                    }
                }
            } 
            else {
                dp[i] = dp[i+1];
                if( s[i + 1] == '*') {
                    if( i == size - 2) {
                         if( s[i] == '1')  {
                            dp[i] += 9;
                        } else if (s[i] == '2') {
                            dp[i] += 6;
                        } 
                    } else {
                        if( s[i] == '1')  {
                            dp[i] += 8 + dp[i + 2];
                        } else if (s[i] == '2') {
                            dp[i] += 5 + dp[i + 2];
                        } 
                    }
                } else {
                    if((s[i]-'0')*10 + (s[i+1]-'0') <=26)
                    {
                        if(i==s.size()-2)
                        {
                            dp[i] += 1;
                        }
                        else
                        {
                            dp[i] += dp[i+2];
                        }
                    }
                }
            }
        }
        return dp[0] % 1000000007;
    }
};
