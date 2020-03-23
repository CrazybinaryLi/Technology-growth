/*BST的后序序列的合法序列是，对于一个序列S，最后一个元素是x （也就是根），
/如果去掉最后一个元素的序列为T，那么T满足：T可以分成两段，
前一段（左子树）小于x，后一段（右子树）大于x，且这两段（子树）都是合法的后序序列。*/
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.size()==0) return false;
        return VerifySquenceOfBST(sequence,0,sequence.size()-1);
    }

private:
    bool VerifySquenceOfBST(vector<int>& sequence, int start , int end){
        if(sequence.size()==1||start>=end) return true;
        int root=sequence[end];//根值
        int l=start;
        while(sequence[l]<root&&l<sequence.size()) l++;
        l--;
        int r=l+1;
        while(sequence[r]>root&&r<sequence.size()) r++;
        r--;
        if(r!=end-1) return false;
        return VerifySquenceOfBST(sequence,start,l)&&VerifySquenceOfBST(sequence,l+1,r);
    }
};
