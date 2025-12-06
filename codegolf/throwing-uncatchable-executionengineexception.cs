/*

The shortest C# code that generates an uncatchable ExecutionEngineException wins. You are not allowed to call FailFast directly or indirectly.

*/

using System;
using System.Threading;

/*

@Rainbolt

Generates an ExecutionEngineException inside of a thread, so it can't be caught.

*/

class Program
{
	static void Main()
	{
		while (true)
		{
			try
			{
				ThreadPool.QueueUserWorkItem(_ => { throw new ExecutionEngineException(); });
			}
			catch (Exception)
			{
				Console.WriteLine("CAUGHT EXCEPTION");
			}
		}
	}
}
