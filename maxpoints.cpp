/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int len = points.size();
        if (len <=2)
        {
            return len;
        }
        map<double, int> mm;
        double kk = 0; 
        int max = 0;
        for (int i = 0; i < len; i++)
        {
            int du = 0;
            mm.clear();
            for (int j = 0; j < len; j++)
            {
                if (i == j)continue;
                if (points[i].x == points[j].x &&
                    points[i].y == points[j].y)
                {
                    du++;
                    continue;
                }
                else if (points[i].x == points[j].x)
                {
                    mm[INT_MAX]++;
                }
                else
                {
                    kk = (double)(points[j].y - points[i].y) / (points[j].x - points[i].x);
                    mm[kk]++;
                }
            }
            if (du > max)
            {
                max = du;
            }
            for (auto nn : mm)
            {
                if (nn.second + du> max)
                {
                    max = nn.second +du;
                }
            }
        }
        return max + 1;
    }
}
