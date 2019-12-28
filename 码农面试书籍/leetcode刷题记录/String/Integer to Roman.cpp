class Solution {
public:
    string intToRoman(int nums) {
        map<string,int> num;
        num["I"]=1;
        num["IV"]=4;
        num["V"]=5;
        num["IX"]=9;
        num["X"]=10;
        num["XL"]=40;
        num["L"]=50;
        num["XC"]=90;
        num["C"]=100;
        num["CD"]=400;
        num["D"]=500;
        num["CM"]=900;
        num["M"]=1000;
        string s1="";//个位
        string s2="";//十位
        string s3="";//百位
        string s4="";//千位
        int decimal=1;
        while(nums>0) {
            int a=nums%10;
            a*=decimal;
            decimal*=10;
            nums/=10;
            if(a<10) {
                while(a-num["IX"]>=0) {
                    a-=num["IX"];
                    s1+="IX";
                }
                while(a-num["V"]>=0) {
                    a-=num["V"];
                    s1+="V";
                }
                while(a-num["IV"]>=0) {
                    a-=num["IV"];
                    s1+="IV";
                }
                while(a-num["I"]>=0) {
                    a-=num["I"];
                    s1+="I";
                }
            } else if(a<100) {
                while(a-num["XC"]>=0) {
                    a-=num["XC"];
                    s2+="XC";
                }
                while(a-num["L"]>=0) {
                    a-=num["L"];
                    s2+="L";
                }
                while(a-num["XL"]>=0) {
                    a-=num["XL"];
                    s2+="XL";
                }
                while(a-num["X"]>=0) {
                    a-=num["X"];
                    s2+="X";
                }
            } else if(a<1000) {
                while(a-num["CM"]>=0) {
                    a-=num["CM"];
                    s3+="CM";
                }
                while(a-num["D"]>=0) {
                    a-=num["D"];
                    s3+="D";
                }
                while(a-num["CD"]>=0) {
                    a-=num["CD"];
                    s3+="CD";
                }
                while(a-num["C"]>=0) {
                    a-=num["C"];
                    s3+="C";
                }
            } else {
                while(a-num["M"]>=0){
                    a-=num["M"];
                    s4+="M";
                }
            }
        }
        string res;
        if(s4!="") res+=s4;
        if(s3!="") res+=s3;
        if(s2!="") res+=s2;
        if(s1!="") res+=s1;
        return res;
    }
};
