

#include <Core/App.h>
#include <Editor.h>

int main()
{
	
#ifdef LICH_EDITOR
	EditorLich::Editor editor;
	editor.Run();
#endif // LICH_EDITOR

#ifdef LICH_GAME
	Core::App app;
	app.Initialize();
	app.Run();
	app.Close();
#endif // LICH_GAME



	return 0;
}