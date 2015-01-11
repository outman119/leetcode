class MinStack {
public:
    void push(int x) {
		realstack.push(x);
		if (minstack.empty())
		{
			minstack.push(x);
		}
		else
		{
			if (minstack.top() >= x)
			{
				minstack.push(x);
			}
		}
	}

	void pop() {
		int tmp = realstack.top();
		realstack.pop();
		if (minstack.top() == tmp)
		{
			minstack.pop();
		}
	}

	int top() {
		return realstack.top();
	}

	int getMin() {
		return minstack.top();
	}
private:
	stack<int> realstack;
	stack<int> minstack;
};
