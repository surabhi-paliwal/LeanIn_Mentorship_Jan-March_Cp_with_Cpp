class Solution {
public:
    int myAtoi(string str) {
        int sign = 1;
        int i = 0;
        for (; i < str.size(); ++i)
        {
            if (str[i] == '-')
                sign = -1;
            if (str[i] == '+' || str[i] == '-')
            {
                i++;
                break;
            }
            if (isdigit(str[i]))
                break;
            if (str[i] != ' ' && !isdigit(str[i]))
                return 0;
        }
        int num = 0;
        for (; i < str.size(); ++i)
        {
            if (!isdigit(str[i]))
                break;
            else
            {
                int digit = str[i] - '0';
                if (sign == 1 && (num > INT_MAX / 10 || num == INT_MAX / 10 && digit > INT_MAX % 10))
                    return INT_MAX;
                else if (sign == -1 && (-num < INT_MIN / 10 || -num == INT_MIN / 10 && -digit < INT_MIN % 10))
                    return INT_MIN;
                num = num * 10 + digit;
            }
        }
        return num * sign;
    }
};
