<?php
/**
 * * @file
 * * Default theme implementation for rendering job post contact information
 * *
 * * Available variables:
 * * - $contact_id: the node ID asociated with the job posting
 * * - $contact:
 * the name of the job post contact
 * */
?>
<div id="contact-<?php print $contact_id ?>" class="contact">
<div class="contacted-by-message">
<hr>
 <?php print $contact; ?>
</div>
</div>
