/************************************
 * file enc : utf8
 * author   : wuyanyi09@gmail.com
************************************/
#ifndef CPPJIEBA_SEGMENT_H
#define CPPJIEBA_SEGMENT_H

#include <algorithm>
#include <set>
#include "Trie.h"
#include "globals.h"

namespace CppJieba
{
	class Segment
	{
		private:
			string _encoding;
			vector<string> _encVec;
			Trie _trie;
		public:
			Segment();
			~Segment();
		public:
			bool init();
			bool setEncoding(const string& enc);
			bool loadSegDict(const string& filePath);
			bool dispose();
		public:
			bool cutDAG(const string& chStr, vector<string>& res);
			double getWordWeight(const string& word);

		private:
			bool _calcDAG(const string& uniStr, vector<vector<uint> >& dag);
			bool _calcDP(const string& uniStr, const vector<vector<uint> >& dag, vector<pair<int, double> >& res);
			bool _cutDAG(const string& uniStr, const vector<pair<int, double> >& dp, vector<string>& res);

	};
}

#endif
