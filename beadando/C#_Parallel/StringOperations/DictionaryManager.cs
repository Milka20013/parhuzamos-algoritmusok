using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace StringOperations
{
    public class DictionaryManager
    {
        public string[] Dict { get; private set; }

        public DictionaryManager(string fileName)
        {
            Dict = ReadDictionary(fileName);
            Array.Sort(Dict);
        }
        public void CleanDictionary(string abc)
        {
            HashSet<string> cleanDict = new HashSet<string>();
            for (int i = 0; i < Dict.Length; i++)
            {
                for (int j = 0; j < Dict[i].Length; j++)
                {
                    if (!abc.Contains(Dict[i][j]))
                    {
                        Dict[i] = "";
                        break;
                    }
                }
                cleanDict.Add(Dict[i]);
            }
            cleanDict.Remove("");
            Dict = cleanDict.ToArray();
        }
        private string[] ReadDictionary(string fileName)
        {
            string[] rawText = File.ReadAllLines(fileName);
            return ClearDictionary(rawText);
        }
        private string[] ClearDictionary(string[] dict)
        {
            List<string> words = new List<string>();
            for (int i = 0; i < dict.Length; i++)
            {
                if (dict[i].Length >= 3)
                {
                    words.Add(dict[i]);
                }
            }
            return words.ToArray();
        }
        public bool WordIsInDictionary(string word)
        {
            return Array.BinarySearch(Dict, word) >= 0;
        }
        public string GetABC()
        {
            HashSet<char> letters = new HashSet<char>();
            for (int i = 0; i < Dict.Length; i++)
            {
                for (int j = 0; j < Dict[i].Length; j++)
                {
                    letters.Add(Dict[i][j]);
                }
            }
            letters.Remove('@');
            char[] abc = letters.ToArray();
            Array.Sort(abc);
            return new string(abc);
        }
    }
}
