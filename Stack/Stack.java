public class Stack{

    private int maxSize;
    private int[] stackArray;
    private int top;

    public Stack(int size){
        this.maxSize = size;
        this.stackArray = new int[maxSize];
        this.top = -1;
    }

    public void push(int ele){
        if(isFull()){
            System.out.println("Stack Overflow");
            return;
        }
        stackArray[++top] = ele;
        System.out.println(ele+" Pushed");
    }

    public void pop(){
        if(isEmpty()){
            System.out.println("Stack Underflow");
            return;
        }
        int ele = stackArray[top];
        System.out.println(ele + " Popped");
        top--;
    }

    public boolean isEmpty(){
        return (top == -1);
    }

    public void peek(){
        System.out.println(stackArray[top] + " is on the top");
    }

    public boolean isFull(){
        return (top == maxSize-1);
    }

    public void printStack(){
        if(isEmpty()){
            System.out.println("Stack empty");
            return;
        }
        for(int i=top; i>=0; i--){
            System.out.println("Printing Stack");
            System.out.println(stackArray[i]);
        }
    }

    public static void main(String[] args){
        Stack st = new Stack(5);
        st.push(10);
        st.push(20);
        st.printStack();
        st.push(30);
        st.push(40);
        st.printStack();
        st.pop();
        st.pop();
        st.pop();
        st.pop();
        st.pop();

    }
}