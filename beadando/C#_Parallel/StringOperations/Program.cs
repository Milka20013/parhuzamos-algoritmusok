using System;
using System.Threading.Tasks;
using System.Diagnostics;

namespace StringOperations
{
    internal class Program
    {
        static void Main(string[] args)
        {
            DictionaryManager dictionary = new DictionaryManager("Dictionary.txt");
            dictionary.CleanDictionary("AÁBCDEÉFGHIJKLMNOÓÖŐPRSTYUÚÜŰVWXZ");
            ABC abc = new ABC(dictionary.GetABC());
            Calculator calculator = new Calculator(abc,5000);
            StringN.calculator = calculator;
            StringN str1 = null;
            StringN str2 = null;
            char mode = '+';
            bool doParallel = false;
            int maxNumberOfWords = 30;
            if (args.Length >= 1)
            {
                doParallel = args[0] == "parallel";
                if (args[0] == "h" || args[0] == "help")
                {
                    Console.WriteLine("Intended use is:");
                    Console.WriteLine("[name] [parallel] [number of words]");
                    Console.WriteLine("[name of the program] [if parallel, then program runs in parallel] [number of words to find in Dictionary.txt]");
                    Console.WriteLine("[name] [str1] [operator] [str2] [abc]");
                    Console.WriteLine("[name of the program] [left string] [what to do with strings] [right string]");
                    return;
                }
            }
            if (args.Length == 2)
            {
                maxNumberOfWords = int.Parse(args[1]);
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
            if (doParallel)
            {
                Console.WriteLine("Parallel Mode");
                AddWordsInDictParallel(dictionary, maxNumberOfWords);
            }
            else
            {
                if (str1 == null)
                {
                    Console.WriteLine("Sequential Mode");
                    AddWordsInDictSec(dictionary, maxNumberOfWords);
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
            }
            stp.Stop();
            Console.WriteLine("Elapsed time: {0} s",(double)stp.ElapsedMilliseconds / 1000.0);
        }

        static void AddWordsInDictParallel(DictionaryManager dictionary, int maxNumberOfWords)
        {
            int numberOfWords = 0;
            Parallel.For(0, dictionary.Dict.Length,
            (index, state) => {
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

        static void AddWordsInDictSec(DictionaryManager dictionary, int maxNumberOfWords)
        {
            int numberOfWords = 0;
            for (int i = 0; i < dictionary.Dict.Length; i++)
            {
                StringN text1 = dictionary.Dict[i];
                for (int j = i; j < dictionary.Dict.Length; j++)
                {
                    StringN text2 = dictionary.Dict[j];
                    StringN result = text1 + text2;
                    if (dictionary.WordIsInDictionary(result.str))
                    {
                        Console.WriteLine("{0} + {1} = {2}", text1, text2, result.str);
                        numberOfWords++;
                        if (numberOfWords == maxNumberOfWords)
                        {
                            return;
                        }
                    }
                }
            }
       
        }
    }
}
