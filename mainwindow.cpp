#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>
#include <cstdlib>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Enable the event Filter
    qApp->installEventFilter(this);
    srand(time(NULL));
}

MainWindow::~MainWindow()
{
    delete ui;
    while(!itemList.isEmpty())
    {
        delete itemList.at(itemList.length()-1);
        itemList.pop_back();
    }
    while(!birdList.isEmpty())
    {
        delete birdList.at(birdList.length()-1);
        birdList.pop_back();
    }
    delete pig1;
    disconnect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    disconnect(this,SIGNAL(quitGame()),this,SLOT(QUITSLOT()));

}

void MainWindow::showEvent(QShowEvent *)
{
    // Setting the QGraphicsScene
    scene = new QGraphicsScene(0,0,width(),ui->graphicsView->height());

    QPixmap bg_pic;
    bg_pic.load(":image/background.jpg");
    bg_pic = bg_pic.scaled(width(),height());
    QBrush *br;
    br = new QBrush(bg_pic);
    scene->setBackgroundBrush(*br);

    ui->graphicsView->setScene(scene);
    // Create world
    world = new b2World(b2Vec2(0.0f, -9.8f));
    world->SetContactListener(new AngryBirdContactListener);
    // Setting Size
    GameItem::setGlobalSize(QSizeF(32,18),size());
    // Set score
    score=0;
    // Create item for "game over" screen.
    endof_game.setPixmap(QPixmap(":image/game_over.png").scaled(width()/3,height()/3));
    endof_game.setPos((qreal)width()/3,(qreal)100.0);
    // Create background (You can edit here)
    itemList.push_back(new Land(16,1.5,32,3,QPixmap(":/ground.png").scaled(width(),height()/6.0),world,scene));
    itemList.push_back(new Land(32,6.0,0.3,6.0,QPixmap("").scaled(10,height()/3.0),world,scene));
    itemList.push_back(new Land(2.0,10.5,0.1,15.0,QPixmap("").scaled(10,height()/3.0),world,scene));

    itemList.push_back(new WoodBar(18.0,13.0,0.6,4.0,&timer,world,scene));
    itemList.push_back(new WoodBar(17.0,7.0,0.6,4.0,&timer,world,scene));
    itemList.push_back(new WoodBar(19.0,10.0,0.6,4.0,&timer,world,scene));
    itemList.at(5)->g_body->SetTransform(itemList.at(5)->g_body->GetPosition(),1.57079633);
    itemList.push_back(new WoodBar(21.0,7.0,0.6,4.0,&timer,world,scene));
    itemList.push_back(new WoodBar(28.0,7.0,0.6,4.0,&timer,world,scene));

    // Create enemy
    pig1=new Pig(18.0f,5.5f,0.27f,&timer,world,scene);

    // Create bird,shooter,boolean condition
    game_over=false;
    ready_b=false;
    shoot_b=true;
    moved_b=false;
    bird_count=0;

    QPixmap pic_shooter(":image/shooter.png");
    pic_shooter=pic_shooter.scaled(150*0.4,150.0);
    shooter.setPixmap(pic_shooter);
    QPointF mappedPoint;
    mappedPoint.setX(((6.0f-2.0f/2) * width())/32.0f);
    mappedPoint.setY((1.0f - (5.5f+5.0f/2)/18.0f) * height());

    shooter.setPos(mappedPoint);
    scene->addItem(&shooter);

    birdList.push_back(new GreenBird(5.5f,9.1f,0.27f,&timer,world,scene));
    birdList.push_back(new BlueBird(0.2f,5.0f+2*2.1f,0.27f,&timer,world,scene));
    birdList.push_back(new YellowBird(0.2f,5.0f+2.1f,0.27f,&timer,world,scene));
    birdList.push_back(new RedBird(0.2f,5.0f,0.27f,&timer,world,scene));

    // Timer
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    connect(this,SIGNAL(quitGame()),this,SLOT(QUITSLOT()));
    stopped=false;
    timer.start(100/6);
}
void MainWindow::genBird()
{

}

bool MainWindow::eventFilter(QObject *, QEvent *event)
{
    // Hint: Notice the Number of every event!
    if(event->type() == QEvent::KeyPress)
    {
        QKeyEvent* k_event=static_cast<QKeyEvent*>(event);
        if(k_event->key() == Qt::Key_E)
        {
            this->close();
        }

        if(k_event->key() == Qt::Key_T)
        {
            if(!stopped)
            {
                timer.stop();
                stopped=true;
            }
            else
            {
                timer.start(100/6);
                stopped=false;
            }

        }
        if(k_event->key() == Qt::Key_R)
        {
            //Reset score
            score=0;
            //Reset background
            itemList.at(3)->g_body->SetTransform(b2Vec2(18.0,13.0),0);
            itemList.at(3)->g_body->SetLinearVelocity(b2Vec2(0.0,0.0));
            itemList.at(3)->g_body->SetAngularVelocity(0.0);

            itemList.at(4)->g_body->SetTransform(b2Vec2(17.0,7.0),0);
            itemList.at(4)->g_body->SetLinearVelocity(b2Vec2(0.0,0.0));
            itemList.at(4)->g_body->SetAngularVelocity(0.0);

            itemList.at(5)->g_body->SetTransform(b2Vec2(19.0,10.0),1.57079633);
            itemList.at(5)->g_body->SetLinearVelocity(b2Vec2(0.0,0.0));
            itemList.at(5)->g_body->SetAngularVelocity(0.0);

            itemList.at(6)->g_body->SetTransform(b2Vec2(21.0,7.0),0);
            itemList.at(6)->g_body->SetLinearVelocity(b2Vec2(0.0,0.0));
            itemList.at(6)->g_body->SetAngularVelocity(0.0);

            itemList.at(7)->g_body->SetTransform(b2Vec2(28.0,7.0),0);
            itemList.at(7)->g_body->SetLinearVelocity(b2Vec2(0.0,0.0));
            itemList.at(7)->g_body->SetAngularVelocity(0.0);

            //Reset enemy
            delete pig1;
            pig1=new Pig(18.0f,5.5f,0.27f,&timer,world,scene);
            pig1->g_body->SetTransform(b2Vec2(18.0f,5.5f),0);
            pig1->g_body->SetLinearVelocity(b2Vec2(0,0));
            // Reset bird,shooter,boolean condition
            while(!birdList.isEmpty())
            {
                delete birdList.at(birdList.length()-1);
                birdList.pop_back();
            }

            ready_b=false;
            shoot_b=true;
            moved_b=false;
            bird_count=0;
            if(game_over)
            {
                scene->removeItem(&endof_game);
                game_over=false;
            }


            birdList.push_back(new GreenBird(5.5f,9.1f,0.27f,&timer,world,scene));
            birdList.push_back(new BlueBird(0.2f,5.0f+2*2.1f,0.27f,&timer,world,scene));
            birdList.push_back(new YellowBird(0.2f,5.0f+2.1f,0.27f,&timer,world,scene));
            birdList.push_back(new RedBird(0.2f,5.0f,0.27f,&timer,world,scene));

        }
    }
    if(event->type() == QEvent::MouseButtonPress)
    {
        /* TODO : add your code here */
        //std::cout << "Press !" << std::endl ;
        //std::cout << itemList.at(1)->g_body->GetPosition().y <<" "<<itemList.at(1)->g_pixmap.pos().y()<<std::endl ;

        QMouseEvent* m_event=static_cast<QMouseEvent*>(event);
        //std::cout <<18.0-18.0*m_event->pos().y()/540.0<<" "<< m_event->pos().y()<<std::endl ;

        shoot_b=true;
        if(shoot_b)
        {
            if(m_event->pos().x() > 150 && m_event->pos().x() < 150+60)
            {
                if(m_event->pos().y() > 267 && m_event->pos().y() < 267+60)
                {
                    ready_b=true;
                    end_x = (float)(m_event->pos().x()) * 32.0f / (size().width());
                    end_y = 18.0f - (float)(m_event->pos().y()) * 18.0f / (size().height());
                    // Reallocate the current bird if it floats away.
                    birdList.at(bird_count)->setLinearVelocity(b2Vec2(0,0));
                    birdList.at(bird_count)->g_body->SetTransform(b2Vec2(5.5f,9.1f),0);

                }
            }
        }

        if(bird_count != 0 && birdList.at(bird_count-1)->show_b)
        {
            if(!(m_event->pos().x() > 150 && m_event->pos().x() < 150+60) || !(m_event->pos().y() > 267 && m_event->pos().y() < 267+60))
            {
                    birdList.at(bird_count-1)->showFeature();
            }
        }
    }

    if(event->type() == QEvent::MouseMove)
    {
        /* TODO : add your code here */
        //std::cout << "Move !" << std::endl ;
       QMouseEvent* m_event=static_cast<QMouseEvent*>(event);
       if(ready_b && bird_count < max_bird)
        {
           if(m_event->pos().x() <= 180)
           {
               ini_x = (float)(m_event->pos().x()) * 32 / (size().width());
               ini_y = 18.0f - (float)(m_event->pos().y()) * 18.0f / (size().height());
               float delt_x,delt_y;
               delt_x= fabs(ini_x-end_x)>2.0f ? 2.0f*(ini_x-end_x)/abs(ini_x-end_x) : (ini_x-end_x);
               delt_y= fabs(ini_y-end_y)>2.0f ? 2.0f*(ini_y-end_y)/abs(ini_y-end_y) : (ini_y-end_y);
               birdList.at(bird_count)->g_body->SetTransform(b2Vec2(delt_x+5.5f,delt_y+9.1f),0.0);
               birdList.at(bird_count)->paint();
               moved_b=true;
               //std::cout << "Move !" << std::endl ;
           }
        }
       else
           ready_b=false;
    }
    if(event->type() == QEvent::MouseButtonRelease)
    {
        /* TODO : add your code here */
        //std::cout << "Release !" << std::endl ;
        if(moved_b && shoot_b )
        {
            if(fabs(end_x-ini_x)>0.7f  ||  fabs(end_y-ini_y)>0.7f)
            {
               b2Vec2 speed =b2Vec2((int)4.5*(end_x-ini_x), (int)5*(end_y-ini_y)) ;
               birdList.at(bird_count)->setLinearVelocity(speed);
               birdList.at(bird_count)->g_body->SetGravityScale(1);

               birdList.at(bird_count)->show_b=true;
               ++bird_count;
               ready_b=false;
               shoot_b=false;
               moved_b=false;
               set_newB=true;
           }
            else
            {
                //when the length of mouse drag is too short, then abandon launching.
                birdList.at(bird_count)->g_body->SetTransform(b2Vec2(5.5f,9.1f),0);
                ready_b=false;
            }
        }

    }
    return false;
}
int MainWindow::score = 0;
void MainWindow::addScore(int incre)
{
    score+=incre;
}

void MainWindow::closeEvent(QCloseEvent *)
{
    // Close event
    emit quitGame();
}

void MainWindow::tick()
{
    world->Step(1.0/60.0,6,2);
    scene->update();

    if((bird_count != 0 && bird_count < max_bird) && set_newB)
    {
        if(birdList.at(bird_count-1)->g_body->GetPosition().x > 7.0f )
        {
            birdList.at(bird_count)->g_body->SetTransform(b2Vec2(5.5f,9.1f),0.0);
            birdList.at(bird_count)->setLinearVelocity(b2Vec2(0,0));
            set_newB=false;
        }
    }
    std::cout<<score<<std::endl;
    if((bird_count == max_bird || pig1->beenHit() ) && !game_over)
    {
        game_over=true;
        scene->addItem(&endof_game);
    }
}

void MainWindow::QUITSLOT()
{
    // For debug
    std::cout << "Quit Game Signal receive !" << std::endl ;
}
