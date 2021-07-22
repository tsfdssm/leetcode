/*
 * @lc app=leetcode.cn id=770 lang=cpp
 *
 * [770] 基本计算器 IV
 */

// @lc code=start
class Poly
{
private:
    map<list<string>, int> coeffs;

public:
    void update(list<string> key, int val)
    {
        coeffs[key] += val;
    }

    Poly add(Poly &that)
    {
        Poly ans;
        for (auto &m : this->coeffs)
        {
            ans.update(m.first, m.second);
        }
        for (auto &m : that.coeffs)
        {
            ans.update(m.first, m.second);
        }
        return ans;
    }

    Poly sub(Poly &that)
    {
        Poly ans;
        for (auto &m : this->coeffs)
        {
            ans.update(m.first, m.second);
        }
        for (auto &m : that.coeffs)
        {
            ans.update(m.first, -m.second);
        }
        return ans;
    }

    Poly mul(Poly &that)
    {
        Poly ans;
        for (auto &m1 : this->coeffs)
        {
            for (auto &m2 : that.coeffs)
            {
                list<string> newKey;
                for (string s : m1.first)
                {
                    newKey.push_back(s);
                }
                for (string s : m2.first)
                {
                    newKey.push_back(s);
                }
                newKey.sort();
                ans.update(newKey, m1.second * m2.second);
            }
        }
        return ans;
    }

    Poly evaluate(map<string, int> &evalMap)
    {
        Poly ans;
        for (auto &m : this->coeffs)
        {
            int c = m.second;
            list<string> k;
            for (string s : m.first)
            {
                if (evalMap.find(s) != evalMap.end())
                {
                    c *= evalMap[s];
                }
                else
                {
                    k.push_back(s);
                }
            }
            ans.update(k, c);
        }
        return ans;
    }

    vector<string> toVector()
    {
        vector<string> ans;
        vector<list<string>> keys;
        for (auto &m : this->coeffs)
        {
            if (m.second == 0)
                continue;
            keys.push_back(m.first);
        }

        sort(keys.begin(), keys.end(), [](list<string> &a, list<string> &b) -> bool {
            if (a.size() != b.size())
            {
                return (a.size() > b.size());
            }
            else
            {
                auto ita = a.begin();
                auto itb = b.begin();
                while ((ita != a.end()) && (*ita == *itb))
                {
                    ++ita;
                    ++itb;
                }
                return (*ita < *itb);
            }
        });

        for (list<string> &k : keys)
        {
            string w = to_string(this->coeffs[k]);
            for (string s : k)
            {
                w.push_back('*');
                w.append(s);
            }
            ans.push_back(w);
        }
        return ans;
    }
};

class Solution
{
public:
    Poly make(string expr)
    {
        Poly ans;
        list<string> k;
        if (isdigit(expr[0]))
        {
            ans.update(k, stoi(expr));
        }
        else
        {
            k.push_back(expr);
            ans.update(k, 1);
        }
        return ans;
    }

    Poly combine(Poly &left, Poly &right, char symbol)
    {
        if (symbol == '+')
        {
            return left.add(right);
        }
        else if (symbol == '-')
        {
            return left.sub(right);
        }
        else if (symbol == '*')
        {
            return left.mul(right);
        }
        else
        {
            throw "unexpected symbol";
        }
    }

    Poly parse(string expr)
    {
        vector<Poly> bucket;
        vector<char> symbols;
        int i = 0;
        while (i < expr.size())
        {
            if (expr[i] == '(')
            {
                int c = 0;
                int j = i;
                for (; j < expr.size(); ++j)
                {
                    if (expr[j] == '(')
                    {
                        ++c;
                    }
                    else if (expr[j] == ')')
                    {
                        --c;
                    }
                    if (c == 0)
                    {
                        break;
                    }
                }
                bucket.push_back(parse(expr.substr(i + 1, j - i - 1)));
                i = j;
            }
            else if (isdigit(expr[i]) || isalpha(expr[i]))
            {
                int j = i;
                for (; j < expr.size(); ++j)
                {
                    if (expr[j] == ' ')
                    {
                        break;
                    }
                }
                bucket.push_back(make(expr.substr(i, j - i)));
                i = j;
            }
            else if (expr[i] != ' ')
            {
                symbols.push_back(expr[i]);
            }
            ++i;
        }

        for (int j = symbols.size() - 1; j >= 0; --j)
        {
            if (symbols[j] == '*')
            {
                bucket[j] = combine(bucket[j], bucket[j + 1], '*');
                bucket.erase(bucket.begin() + j + 1);
                symbols.erase(symbols.begin() + j);
            }
        }

        if (bucket.empty())
        {
            return Poly();
        }
        Poly ans = bucket[0];
        for (int j = 0; j < symbols.size(); ++j)
        {
            ans = combine(ans, bucket[j + 1], symbols[j]);
        }

        return ans;
    }

    vector<string> basicCalculatorIV(string expression, vector<string> &evalvars, vector<int> &evalints)
    {
        map<string, int> evalMap;
        for (int i = 0; i < evalvars.size(); ++i)
        {
            evalMap[evalvars[i]] = evalints[i];
        }

        return parse(expression).evaluate(evalMap).toVector();
    }
};
// @lc code=end
