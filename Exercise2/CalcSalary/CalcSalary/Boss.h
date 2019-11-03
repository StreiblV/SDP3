#ifndef BOSS_H
#define BOSS_H

#include <string>

class Boss {
public:
	virtual std::string GetType() const override;

	virtual void SetProducedPieces() override;
	virtual void SetSoldPieces() override;
	virtual std::size_t GetProdPieces() const override;
	virtual std::size_t GetSoldPieces() const override;
	virtual std::string GetNickname() const = 0;

};

#endif //BOSS_H
