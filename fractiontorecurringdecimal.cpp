class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
		{
			return "0";
		}
		if (denominator == 0)
		{
			return NULL;
		}
		long long num = numerator;
		long long den = denominator;
		string ret;
		if ((num < 0) ^ (den < 0))
		{
			ret += '-';
			num = abs(num);
			den = abs(den);
		}
		
		long long rr = num / den;
		ret += to_string(rr);
		rr = num % den;
		if (rr == 0)
		{
			return ret;
		}
		ret += '.';
		map<long long, int>m;
		while (rr)
		{
			if (m.find(rr) != m.end())
			{
				ret.insert(m[rr], 1, '(');
				ret += ')';
				break;
			}
			m[rr] = ret.size();
			rr *= 10;
			ret += to_string(rr / den);
			rr = rr % den;
		}
		return ret;
    }
};
