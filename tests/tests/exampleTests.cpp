#include <doctest.h>
#include <doctest/trompeloeil.hpp>
#include <exampleMock.hpp>

using trompeloeil::_;

TEST_CASE("Example Test"){

	cMock mock;
	bool status;

	SUBCASE("Require a single call of a mocked function."){
			REQUIRE_CALL(mock,example(3))
				.RETURN(true);

			status = mock.example(3);
			CHECK(status == true);
	}
}
