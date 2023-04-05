struct Trie {
    public: 
        bool finish; // 끝나는 지점을 표시해줌
        Trie* next[26]; // 26가지 알파벳에 대한 트라이
        Trie() {
            finish = false;
            memset(next, 0, sizeof(next));
        }
        ~Trie() {
            for (int i = 0; i < 26; i++)
                if (next[i])
                    delete next[i];
        }
}
