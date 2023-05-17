using System;
using System.Threading.Tasks;
using System.Diagnostics;
using System.Reflection;

namespace StringOperations
{
    internal class Program
    {
        static void Main(string[] args)
        {
            DictionaryManager dictionary = new DictionaryManager("Dictionary.txt");
            dictionary.CleanDictionary("AÁBCDEÉFGHIJKLMNOÓÖŐPRSTYUÚÜŰVWXZ");
            ABC abc = new ABC(dictionary.GetABC());
            Calculator calculator = new Calculator(abc, 5000);
            StringN.calculator = calculator;
            StringN str1 = null;
            StringN str2 = null;
            char mode = '+';
            int maxNumberOfWords = 30;
            int numberOfThreads = 1;
            if (args.Length >= 1)
            {
                if (args[0] == "h" || args[0] == "help")
                {
                    Console.WriteLine("Intended use is:");
                    Console.WriteLine("[name] [number of words] [number of threads]");
                    Console.WriteLine("[name of the program] [number of words to find in Dictionary.txt] [number of threads]");
                    Console.WriteLine("[name] [str1] [operator] [str2] [abc]");
                    Console.WriteLine("[name of the program] [left string] [what to do with strings] [right string] [abc which we generate the word in]");
                    return;
                }
            }
            if (args.Length == 2)
            {
                maxNumberOfWords = int.Parse(args[0]);
                numberOfThreads = int.Parse(args[1]);
            }
            if (args.Length == 4)
            {
                str1 = new StringN(args[0]);
                mode = args[1][0];
                mode = char.ToLower(mode);
                str2 = new StringN(args[2]);
                //make abc out of the words plus the given abc (so it always works)
                ABC abc2 = new ABC(ABC.GenerateABC(args[0] + args[2] + args[3]));
                Calculator calculator2 = new Calculator(abc2, (args[0].Length + args[1].Length) * 10);
                StringN.calculator = calculator2;
            }
            Stopwatch stp = new Stopwatch();
            stp.Start();
            if (str1 == null)
            {
                Console.WriteLine("Word adding in dict with {0} threads", numberOfThreads);
                AddWordsInDictParallel(dictionary, maxNumberOfWords, numberOfThreads);
            }
            else
            {
                StringN result = null;
                switch (mode)
                {
                    case '+':
                        result = str1 + str2;
                        break;
                    case '-':
                        result = str1 - str2;
                        break;
                    case '*':
                        result = str1 * str2;
                        break;
                    case '/':
                        result = str1 / str2;
                        break;
                    case '%':
                        result = str1 % str2;
                        break;
                    default:
                        break;
                }
                if (result != null)
                {
                    Console.WriteLine(result.str);
                }
            }
            stp.Stop();
            Console.WriteLine("Elapsed time: {0} s", (double)stp.ElapsedMilliseconds / 1000.0);
        }

        static void AddWordsInDictParallel(DictionaryManager dictionary, int maxNumberOfWords, int numberOfThreads)
        {
            int numberOfWords = 0;
            Parallel.For(0, dictionary.Dict.Length, new ParallelOptions { MaxDegreeOfParallelism = numberOfThreads },
            (index, state) =>
            {
                StringN text1 = dictionary.Dict[index];
                for (int j = index; j < dictionary.Dict.Length; j++)
                {
                    StringN text2 = dictionary.Dict[j];
                    StringN result = text1 + text2;
                    if (dictionary.WordIsInDictionary(result.str))
                    {
                        Console.WriteLine("{0} + {1} = {2}", text1, text2, result.str);
                        numberOfWords++;
                        if (numberOfWords == maxNumberOfWords)
                        {
                            state.Stop();
                        }
                    }
                }
            });
        }
    }
}
