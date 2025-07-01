#include <linux/module.h>
#include <linux/spi/spi.h>

static int sx130x_probe(struct spi_device *spi)
{
	pr_info("Probing sx130x\n");
	return 0;
}

static void sx130x_remove(struct spi_device *spi)
{
	pr_info("Removing sx130x\n");
}

static const struct spi_device_id sx130x_id[] = {
	{ .name = "sx1301" },
	{ .name = "sx1302" },
	{ .name = "sx1303" },
	{},
};
MODULE_DEVICE_TABLE(spi, sx130x_id);

static const struct of_device_id sx130x_of_match[] = {
	{ .compatible = "semtech,sx1301" },
	{ .compatible = "semtech,sx1302" },
	{ .compatible = "semtech,sx1303" },
	{ }
};
MODULE_DEVICE_TABLE(of, sx130x_of_match);

static struct spi_driver sx130x_driver = {
	.driver = {
		.name   = "sx130x",
		.of_match_table = sx130x_of_match,
	},
	.id_table = sx130x_id,
	.probe  = sx130x_probe,
	.remove = sx130x_remove,
};

module_spi_driver(sx130x_driver);

MODULE_DESCRIPTION("SPI multiplexer");
MODULE_LICENSE("GPL");
