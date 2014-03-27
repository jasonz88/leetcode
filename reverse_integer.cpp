class Solution {
public:
    int reverse(int x) {
        bool isNeg=false;
        if(0>x){
            x=-x;
            isNeg=true;
        }
        if(10>x) return isNeg?-x:x;
        std::stack<int> s;
        int dv=10;
        int nod=1;
        while(0<x/dv){
            dv*=10;
            nod++;
        }
        int d=0;
        while(1<dv){
            d=x*10/dv;
            s.push(d);
            x-=d*dv/10;
            dv/=10;
        }
        x=0;
        nod--;
        while(!s.empty()){
            d=s.top();
            s.pop();
            x+=d*pow(10,nod--);
        }
        return isNeg?-x:x;
    }
};
