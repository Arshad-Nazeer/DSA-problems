class Solution {
    public boolean lemonadeChange(int[] bills) {
        int fives=0, tens=0; // twenties bills are not required because they are never used as change
        for(int x: bills){
            switch(x){
                case 5: 
                    fives++;
                    break;
                case 10:
                    if(fives==0) return false;
                    fives--;
                    tens++;
                    break;
                case 20:     // A smaller bill can be used to make up a wider range of required changes.
                    if(fives>0 && tens>0){
                        fives--;
                        tens--;
                    }else if(fives>=3) fives-=3;
                    else return false;
                    break;
            }
        }
        return true;
    }
}