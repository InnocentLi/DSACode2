public class LinearSearch {
    private LinearSearch(){

    }
    public int search(int[] data,int target){
        for(int i = 0;i < data.length;i++){
             if(data[i]==target){
                 return i;
             }
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] data = {23,18,12,9,11,232,321,564,32,21};
        LinearSearch ls = new LinearSearch();
        int res = ls.search(data,321);
        System.out.println(res);

        int res2 = ls.search(data,6666);
        System.out.println(res2);


        
     }
}
