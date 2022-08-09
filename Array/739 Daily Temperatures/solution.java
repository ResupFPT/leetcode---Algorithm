import java.util.Stack;

public class solution {

    //this solution have time complexity O(n^2)
    public static int[] dailyTemperatures(int[] temperatures) {
        Stack<Integer> tempStack = new Stack<Integer>();
        int[] answer = new int[temperatures.length];

        for (int i = 0; i < answer.length; i++) {
            int j = i+1;
            while(j<answer.length){
                tempStack.push(temperatures[j]);
                if(tempStack.peek() > temperatures[i]){
                    answer[i] = tempStack.size();
                    tempStack.clear();
                    break;
                }
                j++;
            }
            if(!tempStack.isEmpty()){
                answer[i] = 0;
                tempStack.clear();
            }
        }

        return answer;
    }

    //this solution have time complexity is O(n)
    public static int[] dailyTemperatures2(int[] temperatures) {
        int n = temperatures.length;
        int[] answer = new int[n];
        Stack<Integer> tempStack = new Stack<Integer>();

        for (int currDay = 0; currDay < n; currDay++) {
            int currentTemp = temperatures[currDay];
            while(!tempStack.isEmpty() && temperatures[tempStack.peek()] < currentTemp){
                int preDay = tempStack.pop();
                answer[preDay] = currDay - preDay;
            }

            tempStack.push(currDay);
        }

        return answer;

    }

    public static void main(String[] args) {
        // int[] temperatures = {73,74,75,71,69,72,76,73};
        int[] temperatures = {55,38,53,81,61,93,97,32,43,78};
        int[] answer = dailyTemperatures2(temperatures);
        for (int i = 0; i < answer.length; i++) {
            System.out.print(answer[i] + " ");
        }
    }
}
