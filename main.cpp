#include "mainwindow.h"

#include "UseCase/UseCase.hpp"

#include "Model/BeverageVariety.hpp"
#include "Model/IBeverage.hpp"
#include "Model/Ingredient.hpp"

#include "Adapter/OrderRepository.hpp"
#include "Adapter/PrinterPresenter.hpp"

#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  PrinterPresenter printerPresenter; // IOutput & output
  OrderRepository orderRepository;
  UseCase uc(printerPresenter, orderRepository);

  IBeverage::BeverageType beverageType(IBeverage::BeverageType::Coffee);
  BeverageVariety beverageVariety(BeverageVariety::CoffeeEspresso);
  Ingredient extraIngredient(Ingredient::Sugar);

  bool res = uc.addNewOrder(beverageType, beverageVariety, extraIngredient);
  if (res)
    QMessageBox::information(
        nullptr, "Info", "Coffee Espresso with Sugar ordered", QMessageBox::Ok);
  else
    QMessageBox::critical(nullptr, "Error",
                          "Couldn't order an Expresso with sugar",
                          QMessageBox::Ok);

  auto orderList = orderRepository.getOrders();
  printerPresenter.printOutOrders(orderList);

  // TODO Develop User Interface

  // MainWindow w;
  // w.show();
  return a.exec();
}
