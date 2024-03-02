#include "../lib/KromProgram.h"
#include "../lib/ErrorHandler.h"
#include "../lib/Operator.h"
#include "../lib/AllOperators.h"
#include "../lib/CppProgram.h"

void populateKromStdLib();
void lexString(shared_ptr<SourceFile> file, vector<Token>& tokens);
Action parseFunction(const vector<Token>& tokens, int left, int right, Type leftInType, Type rightInType);

extern Namespace globalNamespace;

KromProgram::KromProgram()
{
	
}

void KromProgram::cleanUp()
{
	
}

void KromProgram::resolveProgram(string inFilename, bool printOutput)
{
	AllOperators::init();
	populateKromStdLib();
	
	//initialProgramPopulation();
	
	//globalFrame.resolve(printOutput);
	
	if (!error.getIfErrorLogged())
	{
		try
		{
			file=shared_ptr<SourceFile>(new SourceFile(inFilename, printOutput));
			
			if (printOutput)
			{
				cout << endl << endl << file->getBoxedString() << endl;
			}
		}
		catch (KromError err)
		{
			err.log();
		}
	}
	
	if (!error.getIfErrorLogged())
	{
		try
		{
			lexString(file, tokens);
		}
		catch (KromError err)
		{
			err.log();
			astRoot=AstVoid::make();
		}
		
		/*
		if (printOutput)
		{
			cout << endl << tableStringFromTokens(tokens, "lexer output") << endl;
		}
		*/
	}
	
	//astRoot=parseFunction(tokens, 0, tokens.size()-1, Void, Void);
	
	if (!error.getIfErrorLogged())
	{
		try
		{
			astRoot=astNodeFromTokens(tokens, 0, tokens.size()-1);
		}
		catch (KromError err)
		{
			err.log();
			astRoot=AstVoid::make();
		}
		
		if (printOutput)
		{
			cout << " ╭──────────────────────╮" << endl;
			cout << " │ abstract syntax tree │" << endl;
			cout << " ╰──────────────────────╯" << endl;
			cout << astRoot->getString() << endl;
			//cout << endl << putStringInBox(astRoot->getString(), "abstract syntax tree") << endl;
			//cout << endl << str::getBoxedString(astRoot->getString(), "abstract syntax tree") << endl;
		}
	}
	
	if (!error.getIfErrorLogged())
	{
		try
		{
			astRoot->setInput(globalNamespace, true, Void, Void);
		}
		catch (KromError err)
		{
			err.log();
			astRoot=AstVoid::make();
		}
		
		try
		{
			actionRoot=astRoot->getAction();
			
			if (printOutput)
			{
				cout << " ╭─────────────╮" << endl;
				cout << " │ action tree │" << endl;
				cout << " ╰─────────────╯" << endl;
				cout << actionRoot->getDescription() << endl;
				//cout << endl << str::getBoxedString(actionRoot->getDescription(), "action tree") << endl;
			}
		}
		catch (KromError err)
		{
			err.log();
		}
	}
	
	/*if (printOutput)
	{
		cout << endl << "C source code:\n" << astRoot->getCSource() << endl;
	}*/
	
}

string KromProgram::getCpp()
{
	try
	{
		CppProgram outProg;
		actionRoot->addToProg(voidAction, voidAction, &outProg);
		return outProg.getCppCode();
	}
 	catch (KromError err)
	{
		err.log();
		return "/* no program due to transpiling error */";
	}
}

void KromProgram::execute()
{
	try
	{
		stackPtr=globalFramePtr=malloc(globalNamespace->getStackFrame()->getSize());
		free(actionRoot->execute(nullptr, nullptr));
		free(globalFramePtr);
		stackPtr=globalFramePtr=nullptr;
	}
	catch (KromError err)
	{
		err.log();
		cout << endl << ">>>>>>    program aborted due to error    <<<<<<" << endl;
	}
}

