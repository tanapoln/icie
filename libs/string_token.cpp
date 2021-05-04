/// Name: string_token
/// Description: Tokenize string with delimiter
/// Guarantee: vector<string> tokenize(string s, string delim) {
vector<string> tokenize(string s, string delim) {
    vector<string> out;
	string::size_type beg = 0;
	for (string::size_type end = 0; (end = s.find(delim, end)) != string::npos; ++end)
	{
		out.push_back(s.substr(beg, end - beg));
		beg = end + 1;
	}

	out.push_back(s.substr(beg));

    return out;
}
