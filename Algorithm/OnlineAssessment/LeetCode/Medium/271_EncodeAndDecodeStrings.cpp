class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        stringstream ss;
        ss << STX;
        
        for(const string& s : strs){
            ss << s << US;
        }
        
        ss << ETX;
        
        return ss.str();
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        int n = s.length();
        vector<string> line;
        
        if(s[0] != STX || s[n - 1] != ETX){
            // invalid, return empty line
            return line;
        }
        
        string src = s.substr(1, n - 2);
        
        split(src, line, US);
        return line;
        
    }

private:
    
    void split(string& s, vector<string>& vec, char delimeter){
        std::istringstream iss(s);
        string token;
        while (std::getline(iss, token, delimeter))
        {
            vec.push_back(token);
        }
    }

private:
    const char STX = '\x02';  // Start of text
    const char ETX = '\x03';  // End of text
    const char US = '\x1F';  // Unit separator
    
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));