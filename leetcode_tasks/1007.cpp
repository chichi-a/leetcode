class Solution {
public:
    int helper(int a, vector<int>& tops, vector<int>& bottoms) {
        int topCount = 0;
        int bottomCount = 0;

        for (int i = 0; i < tops.size(); i++) {
            if (tops[i] != a && bottoms[i] != a) {
                // If neither top nor bottom has 'a', it's impossible to make them equal
                return tops.size() + 1;
            }
            if (tops[i] != a) {
                // If top[i] is not 'a', we need a rotation from the bottom
                topCount++;
            }
            if (bottoms[i] != a) {
                // If bottom[i] is not 'a', we need a rotation from the top
                bottomCount++;
            }
        }

        // Return the minimum number of rotations needed
        return min(topCount, bottomCount);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        if (tops.size() == 1) return 0;

        int size = tops.size();
        int a = tops[0];
        int b = bottoms[0];

        // Try to make all elements in tops or bottoms equal to 'a' or 'b'
        int minRotations = min(helper(a, tops, bottoms), helper(b, tops, bottoms));

        // If minRotations exceeds size, it means it's not possible
        return minRotations > size ? -1 : minRotations;
    }
};
