// 问题：
// 计算零钱是否够用
// 顾客按顺序买柠檬水，每杯5元，顾客给的钱可能是5元、10元、20元
// 当5元不够用时返回false，否则返回true
// 例如[5,5,5,10,20]，返回true


// 思路：
// 此题一开始想法不正确，认为20需要多少个5来抵消，10需要多少个5来抵消，但实际上这些是有顺序关系的，不是简单统计个数就行
// 正确的方法是，设置两个计数器pos5、pos10，然后从头开始遍历
// 当遇到5时，pos5++，表示累计了一个5
// 当遇到10时，pos5--，pos10++，注意这个pos10是关键，因为在20的时候会用上
// 当遇到20时，如果手上pos10不为零，则pos5--，pos10--；如果pos10为零，则pos5-=3
// 整个遍历的过程中，一旦出现pos5小于0，则返回false，否则最后返回true，明显这个是O(n)算法

// 代码
bool lemonadeChange(vector<int>& bills) {        
        int pos5 = 0, pos10 = 0;
        for(size_t i=0; i<bills.size(); i++){
            if(bills[i] == 5)
                pos5 ++;
            else if(bills[i] == 10){
                pos5 --;
                pos10 ++;
            }                
            else{
                if(pos10 > 0){
                    pos5 --;
                    pos10 --;
                }
                else{
                    pos5 -= 3;
                }
            }

            
            if(pos5 < 0)
                return false;
        }
        
        return true;
    }
