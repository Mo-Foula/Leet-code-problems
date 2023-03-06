class Solution {

    public int findKthPositive(int[] arr, int k) {
        LinkedList<Integer> missing= new LinkedList<>();
        int current = 1;
        int index = 0;
        while (missing.size() < k) {
            if (index < arr.length && arr[index] == current) ++index; 
            else missing.addLast(current);
            ++current;
        }
        return missing.get(k - 1);
    }
}
