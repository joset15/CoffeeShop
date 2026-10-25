#ifndef CANCEL_EXISTING_ORDER_UC_HPP
#define CANCEL_EXISTING_ORDER_UC_HPP

#include "IOrderRepository.hpp"
#include "UseCase.hpp"

#include <string>

/// @brief Cancels the orders that have not been served yet.
///
/// Skeleton for a future use case: IOrderRepository has no way to cancel
/// orders yet, so execute() always fails.
class CancelExistingOrderUC : public UseCase
{
public:
  /// @brief
  /// @param name The name of the use case.
  /// @param orderRepository Where the orders are stored.
  CancelExistingOrderUC(std::string name, IOrderRepository &orderRepository);

  /// @brief Cancels the existing orders.
  /// @return False: not implemented yet.
  bool execute() override;

private:
  /// @brief Where the orders are stored (not owned, never null: set from a
  /// reference).
  IOrderRepository *m_OrderRepository;
};

#endif // CANCEL_EXISTING_ORDER_UC_HPP
