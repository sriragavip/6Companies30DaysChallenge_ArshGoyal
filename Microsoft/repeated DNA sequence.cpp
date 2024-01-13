class Solution {
public:
    std::vector<std::string> findRepeatedDnaSequences(std::string s) {
        if (s.length() < 10) return {};

        std::vector<std::string> answer;
        std::unordered_map<uint32_t, int> hashTable;
        const uint8_t mapping[256] = {['A'] = 0, ['C'] = 1, ['G'] = 2, ['T'] = 3};

        uint32_t currentSequence = 0;
        #pragma unroll
        for (int i = 0; i < 9; ++i) {
            currentSequence = (currentSequence << 2) | mapping[s[i]];
        }
        
        #pragma unroll
        for (int i = 9; i < s.length(); ++i) {
            currentSequence = ((currentSequence << 2) & 0xFFFFF) | mapping[s[i]];
            hashTable[currentSequence]++;
            if (hashTable[currentSequence] == 2) {
                answer.push_back(s.substr(i - 9, 10));
            }
        }

        return answer;
    }
};