#include <linux/i2c.h>
#include <linux/init.h>
#include <linux/mod_devicetable.h>
#include <linux/module.h>

static int nunchuk_probe(struct i2c_client *client,
        const struct i2c_device_id *id)
{
        pr_info("nunchuk_probe called\n");
        return 0;
}

static int nunchuk_remove(struct i2c_client *client)
{
        pr_info("nunchuk_remove called\n");
        return 0;
}

static const struct i2c_device_id nunchuk_ids[] = {
        { "nunchuk", 0 },
        {}
};
MODULE_DEVICE_TABLE(i2c, nunchuk_ids);

static const struct of_device_id nunchuk_dt_ids[] = {
        { .compatible = "nintendo,nunchuk", },
        {}
};

static struct i2c_driver nunchuk_driver = {
        .driver = {
                .name = "nunchuk",
                .owner = THIS_MODULE,
                .of_match_table = nunchuk_dt_ids,
        },
        .id_table = nunchuk_ids,
        .probe = nunchuk_probe,
        .remove = nunchuk_remove,
};

module_i2c_driver(nunchuk_driver);
MODULE_LICENSE("GPL");
