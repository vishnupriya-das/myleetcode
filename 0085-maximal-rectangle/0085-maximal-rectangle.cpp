
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0;
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int width = n;

                for (int k = i; k < m; k++) {
                    int count = 0;

                    for (int l = j; l < n; l++) {
                        if (matrix[k][l] == '1')
                            count++;
                        else
                            break;
                    }

                    width = min(width, count);

                    ans = max(ans, width * (k - i + 1));
                }
            }
        }

        return ans;
    }
};