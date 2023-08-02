#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
	protected:
		std::string		_type;
	public:
		Animal();
		Animal( Animal const & src );
		virtual ~Animal();
		Animal &		operator=( Animal const & rhs );

		std::string		getType() const;
		virtual void	makeSound() const;
};

#endif
