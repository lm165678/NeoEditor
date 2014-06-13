#include "GLBox.h"
#include "../MWindow/MWindow.h"
#include <MEngine.h>
#include <MLoaders/MImageLoader.h>
#include <MLog.h>
#include <MThread.h>

#include <MMouse.h>
#include <MGui.h>
#include "../MFilesUpdate/MFilesUpdate.h"
#include "../Maratis/Maratis.h"
#include "Callbacks.h"
#include <MCore.h>
#include "../MRenderArray/MRenderArray.h"
#include "MainWindow.h"

#include <FL/Enumerations.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Double_Window.H>

extern MSemaphore updateSemaphore;

extern Fl_Double_Window* main_window;
extern EditorWindow window;

extern void update_scene_tree();

void update_editor(void*)
{
    if(!window.glbox->maratis_init)
        return;

    MInputContext* input = MEngine::getInstance()->getInputContext();

    if(input->isKeyPressed("W"))
    {
        int direction = -1;

        MOCamera * vue = Maratis::getInstance()->getPerspectiveVue();
        vue->setPosition(vue->getPosition() + vue->getRotatedVector(MVector3(0,0,direction*translation_speed)));
        vue->updateMatrix();

        window.glbox->redraw();
    }
    else if(input->isKeyPressed("S"))
    {
        int direction = 1;

        MOCamera * vue = Maratis::getInstance()->getPerspectiveVue();
        vue->setPosition(vue->getPosition() + vue->getRotatedVector(MVector3(0,0,direction*translation_speed)));
        vue->updateMatrix();

        window.glbox->redraw();
    }

    if(input->isKeyPressed("A"))
    {
        int direction = -1;

        MOCamera * vue = Maratis::getInstance()->getPerspectiveVue();
        vue->setPosition(vue->getPosition() + vue->getRotatedVector(MVector3(direction*translation_speed,0,0)));
        vue->updateMatrix();

        window.glbox->redraw();
    }
    else if(input->isKeyPressed("D"))
    {
        int direction = 1;

        MOCamera * vue = Maratis::getInstance()->getPerspectiveVue();
        vue->setPosition(vue->getPosition() + vue->getRotatedVector(MVector3(direction*translation_speed,0,0)));
        vue->updateMatrix();

        window.glbox->redraw();
    }

    if(input->isKeyPressed("E"))
    {
        MOCamera * vue = Maratis::getInstance()->getPerspectiveVue();
        vue->setPosition(vue->getPosition()+vue->getRotatedVector(MVector3(0,translation_speed, 0)));
        vue->updateMatrix();

        window.glbox->redraw();
    }
    else if(input->isKeyPressed("C"))
    {
        MOCamera * vue = Maratis::getInstance()->getPerspectiveVue();
        vue->setPosition(vue->getPosition()+vue->getRotatedVector(MVector3(0,-translation_speed, 0)));
        vue->updateMatrix();

        window.glbox->redraw();
    }

    if(Maratis::getInstance()->hasTitleChanged())
    {
        main_window->label(Maratis::getInstance()->getWindowTitle());
        Maratis::getInstance()->setTitleChanged(false);
    }

    MGame* game = MEngine::getInstance()->getGame();
    if(game)
    {
        if(!game->isRunning())
            MFilesUpdate::update();
    }
    else
    {
        MFilesUpdate::update();
    }

    Fl::add_timeout(0.01, update_editor);
}

void GLBox::draw()
{
    MWindow * mwindow = MWindow::getInstance();
    if(!maratis_init)
    {
        MEngine * engine = MEngine::getInstance();
        Maratis * maratis = Maratis::getInstance();

        MRenderingContext * render = engine->getRenderingContext();
        MLOG_INFO("Render version : " << render->getRendererVersion());

        render->setTextureFilterMode(M_TEX_FILTER_NEAREST, M_TEX_FILTER_NEAREST_MIPMAP_NEAREST);
        render->setClearColor(MVector4(0.18, 0.32, 0.45, 1));

        MGui * gui = MGui::getInstance();
        gui->setRenderingContext(render);

        update_scene_tree();

        maratis_init = true;
        reload_editor = true;
    }

    if(reload_editor)
    {
        reload_editor = false;
    }

    Maratis* maratis = Maratis::getInstance();

    MWindow::getInstance()->setViewport(w(), h());
    MEngine::getInstance()->updateRequests();

    maratis->graphicLoop();

    swap_buffers();
}

int GLBox::handle(int event)
{
    //fprintf(stderr, "Handle %d FL_KEYBOARD is %d\n", event, FL_KEYBOARD);
    char key[2] = {0,0};
    switch(event)
    {
    case FL_KEYBOARD:
        {
            if(this != Fl::focus() || Fl::event_ctrl())
                return 0;

            key[0] = toupper(Fl::event_text()[0]);
            MEngine::getInstance()->getInputContext()->downKey(key);

            char keys[27] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

            for(int i = 0; i < sizeof(keys); i++)
            {
                char c[2] = {0,0};
                c[0] = keys[i];

                if(Fl::get_key(keys[i]))
                {
                    MEngine::getInstance()->getInputContext()->downKey(c);
                }
                else
                {
                    MEngine::getInstance()->getInputContext()->upKey(c);
                }
            }

            Fl_Gl_Window::handle(event);
            return isalpha(Fl::event_text()[0]);
        }
        break;

    case FL_KEYUP:
        {
            if(this != Fl::focus())
                return 0;

            char keys[27] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

            for(int i = 0; i < sizeof(keys); i++)
            {
                char c[2] = {0,0};
                c[0] = keys[i];

                if(Fl::get_key(keys[i]))
                {
                    MEngine::getInstance()->getInputContext()->downKey(c);
                }
                else
                {
                    MEngine::getInstance()->getInputContext()->upKey(c);
                }
            }

            Fl_Gl_Window::handle(event);
            return 1;
        }
        break;

    case FL_MOVE:
        {
            MMouse* mouse = MMouse::getInstance();
            mouse->setDirection(mouse_x-Fl::event_x(), mouse_y-Fl::event_y());

            mouse_x = Fl::event_x();
            mouse_y = Fl::event_y();

            mouse->setPosition(mouse_x, mouse_y);

        break;
        }
    case FL_MOUSEWHEEL:
        {
            int direction = Fl::event_dy();

            MOCamera * vue = Maratis::getInstance()->getPerspectiveVue();
            vue->setPosition(vue->getPosition() + vue->getRotatedVector(MVector3(0,0,direction*translation_speed)));
            vue->updateMatrix();

            redraw();
            return 1;
        }
        break;

    case FL_FOCUS:
            //Fl::focus(this);
            return 1;
        break;

    case FL_UNFOCUS:
            return 1;
        break;

    case FL_PUSH:

            Fl::focus(this);

            mouse_x = Fl::event_x();
            mouse_y = Fl::event_y();

            if(Fl::event_button1())
            {
                Maratis::getInstance()->selectObjectsInMainView(MEngine::getInstance()->getLevel()->getCurrentScene());
                ::window.scene_tree->deselect_all();

                Fl_Tree_Item* item = ::window.scene_tree->root();

                update_name = true;
                while((item = ::window.scene_tree->next(item)) != NULL)
                {
                    if(Maratis::getInstance()->getSelectedObjectsNumber() == 0)
                        break;

                    // TODO: Multiple selection!
                    if(item && !strcmp(item->label(), Maratis::getInstance()->getSelectedObjectByIndex(0)->getName()))
                    {
                        update_name = true;
                        ::window.scene_tree->select(item);
                    }
                }

                redraw();
                ::window.special_tab->redraw();
            }
            return 1;
        break;

    case FL_DRAG:
        {
            if(Fl::event_button3())
            {
                MOCamera * vue = Maratis::getInstance()->getPerspectiveVue();

                vue->setEulerRotation(vue->getEulerRotation() + MVector3(mouse_y - Fl::event_y(), 0, mouse_x-Fl::event_x())*0.5*rotation_speed);
                vue->updateMatrix();
            }

            MMouse* mouse = MMouse::getInstance();
            mouse->setDirection(mouse_x-Fl::event_x(), mouse_y-Fl::event_y());

            mouse_x = Fl::event_x();
            mouse_y = Fl::event_y();

            mouse->setPosition(mouse_x, mouse_y);

            if(Fl::event_button1())
            {
                Maratis::getInstance()->transformSelectedObjects();
            }

            redraw();
        }
        break;
    }

    Fl_Tree_Item* item = ::window.scene_tree->first_selected_item();

    if(item)
    {
        update_name = false;
        ::window.scene_tree->deselect(item);
        ::window.scene_tree->select(item);
        ::window.special_tab->redraw();
        update_name = true;
    }

    return Fl_Gl_Window::handle(event);
}